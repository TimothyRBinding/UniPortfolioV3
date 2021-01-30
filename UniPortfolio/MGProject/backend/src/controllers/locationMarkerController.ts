import { getRepository } from 'typeorm' // allows us access to the connection object even though we are in a different file
import { LocationMarker } from '../database/entity/LocationMarker'

async function getAllLocationMarkers(req, res) {
    res.json(
        await getRepository(LocationMarker)
            .createQueryBuilder('locationMarker')
            .leftJoinAndSelect('locationMarker.business', 'business')
            .leftJoinAndSelect('business.images', 'images')
            .getMany(),
    )
}

export default { getAllLocationMarkers }
