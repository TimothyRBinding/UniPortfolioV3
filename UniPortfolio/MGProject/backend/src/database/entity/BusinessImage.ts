import { Entity, Column, PrimaryGeneratedColumn, ManyToOne } from 'typeorm'
import { Business } from './Business'

@Entity()
export class BusinessImage {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    image: Buffer

    @ManyToOne((type) => Business, (business) => business.images)
    business: Business
}
