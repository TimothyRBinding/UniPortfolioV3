import {
    Entity,
    Column,
    PrimaryGeneratedColumn,
    OneToOne,
    JoinColumn,
} from 'typeorm'
import { Business } from './Business'

@Entity()
export class LocationMarker {
    @PrimaryGeneratedColumn()
    id: number

    @Column({ type: 'decimal', precision: 6, scale: 4 })
    longitude: number

    @Column({ type: 'decimal', precision: 6, scale: 4 })
    latitude: number

    @OneToOne(() => Business, (business) => business.locationMarker)
    @JoinColumn()
    business: Business
}
